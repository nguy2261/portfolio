<?php
$city = $_GET['city'];
$city = str_replace(' ','',$city);
$content = @file_get_contents("http://www.weather-forecast.com/locations/".$city."/forecasts/latest");
if ($content) {
    preg_match('/3 Day Weather Forecast Summary:<\/b><span class="read-more-small"><span class="read-more-content"> <span class="phrase">(.*?)</s',$content,$matches);
    echo $matches[1];
} else {
    echo "";
}
?>