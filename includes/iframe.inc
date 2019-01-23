<?php

/**
 * @file
 * Defines menu callback for show image into iframe
 *
 * $object_id : PID of object
 */

function islandora_openseadragon_iframe($object_id) {
        module_load_include('inc', 'islandora_openseadragon', 'includes/utilities');
        $TS = islandora_openseadragon_tile_source($object_id, 'JP2', '');
        $settings = islandora_openseadragon_get_settings($filter_null = TRUE);
        echo('<div id=osdi allowfullscreen style="height: 100%; width: 100%; display: inline-block;"></div>');
        echo('<script src="/sites/all/libraries/openseadragon/openseadragon.js"></script>');
        echo('<script type="text/javascript">');
        echo('var viewer = OpenSeadragon({');
                echo('element: document.getElementById("osdi"),');
//              echo('prefixUrl: "/sites/all/libraries/openseadragon/images/",');
                echo('prefixUrl: "'.$settings['prefixUrl'].'",');
                echo('homeFillsViewer: false,');
                echo('showZoomControl: true,');
                echo('showNavigator:  false,');
                echo('showHomeControl: false,');
                echo('showFullPageControl: true,');
                echo('showRotationControl: true,');
                echo('navigatorPosition: 0,');
                echo('navigationControlAnchor: 2,');
                echo('sequenceMode: false,');
                echo('preserveViewport: true,');
                echo('defaultZoomLevel: 0,');
                echo('constrainDuringPan: false,');
                echo('visibilityRatio: 1,');
                echo('minZoomImageRatio: 0.9,');
                echo('tileSources: "'.$TS.'",');
        echo('});');
        echo('</script>');
        drupal_exit();
}
