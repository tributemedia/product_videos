;(function($){

  function closeLightbox() {
    $('#video-frame iframe').attr('src', '');
    $('#product-video-lightbox').addClass('hide');
    $('#pvl-overlay').addClass('hide');
  }

$(document).ready(function() {

  // Accordian stuffs

  $('.video-group').addClass('closed');
  $('.view-product-videos .view-content .video-category:first .video-group').removeClass('closed').addClass('open');
  $('.video-group.closed').toggle();

  $('.video-category h3').click(function() {
    $('.video-group').addClass('closed');
    $('.video-group.open').animate({
      height: "toggle"
    }, 500);
    $('.video-group.open').removeClass('open');
    $(this).siblings('.video-group').removeClass('closed').addClass('open');
    $(this).siblings('.video-group').animate({
      height: "toggle"
    }, 500);
  });

  // Lightbox stuffs

  $('.video-lightbox').click(function() {
    var videoSrc = $(this).attr('vid-src');

    // If the URL provided has the watch argument, use the following method
    // to form the video src string of the iframe.
    if(videoSrc.indexOf('watch') > 0) {
      videoSrc = videoSrc.replace('watch?v=', 'embed/');
      videoSrc = videoSrc.split('&')[0] + '?rel=0';
    }
    // Otherwise, the video ID is probably the first argument after the last
    // slash. Use this method to build the video src string.
    else {
      vidSrcSplit = videoSrc.split('/');
      videoSrc = 'https://youtube.com/embed/' + vidSrcSplit[vidSrcSplit.length - 1];
    }

    $('#video-frame iframe').attr('src', videoSrc);
    $('#pvl-overlay').removeClass('hide');
    $('#product-video-lightbox').removeClass('hide');
  });
  $('#close-box').click(function() {
    closeLightbox();
  });
  $('#pvl-overlay').click(function() {
    closeLightbox();
  });
});

})(jQuery);
