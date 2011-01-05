// $Id:

/**
 * Prevent Viddler uploads when using buttons not intended to upload.
 */
Drupal.behaviors.viddlerButtons = function(context) {
  // $('input.form-submit', context).bind('mousedown', Drupal.viddler.disableFields);
  $('div.viddler_upload-ahah-wrapper input.form-submit', context).bind('mousedown', Drupal.viddler.progressBar);
};

/**
 * Utility functions for use by Viddler.
 * @param {Object} event
 */
Drupal.viddler = {
  progressBar: function(event) {
    var clickedButton = this;
    var $progressId = $(clickedButton).parents('div.viddler_upload-ahah-wrapper').find('input.viddler-progress');
    
    if ($progressId.size()) {
      var originalName = $progressId.attr('name');
      
      // Replace the name with the required identifier.
      $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

      // Restore the original name after the upload begins.
      setTimeout(function() {
        $progressId.attr('name', originalName);
      }, 1000);

      // Show the progress bar if the upload takes longer than 3 seconds.
      setTimeout(function() {
        $(clickedButton).parents('div.viddler_upload-ahah-wrapper').find('div.ahah-progress-bar').slideDown();
      }, 500);

    }
  }
};