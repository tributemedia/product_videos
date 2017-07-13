# Product Videos
Import support videos from copiercatalog.com, and provide a search fucntionality to find the videos of interest.

## Install

1. Upload module and enable as with any Drupal module.
2. Paste the following code after the closing `</div>` tag for the page. Generally this is the `<div>` with the class of page.
  `<div id="product-video-lightbox" class="hide">
    <div id="close-box">X</div>
    <div id="video-frame">`
      <iframe src="" height="360" width="640"></iframe>
    `</div>
  </div>
  <div id="pvl-overlay" class="hide"></div>`
  
