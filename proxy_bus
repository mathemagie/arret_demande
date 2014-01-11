<?php
$cmd = "/usr/bin/w3m -dump 'http://wap.ratp.fr/siv/schedule?service=next&reseau=bus&lineid=B69&stationid=69_657_708' | grep -A 1 \">\" | sed '/--/d' | sed 's/> //' | sed 's/  //g'";
exec($cmd,$res);
$data_mn= $res[5];
if ($_GET['debug']) {
        print_r($res);
        echo "<br/>";
        echo $data_mn;
        echo "<br/>";
}
$a = explode(' ',$data_mn);
$result = intval($a[0]);
if ($_GET['debug']) {
        echo $result;
        echo "<br/>";
}
if ($result <= 3) {
        echo "1";
}else {
        echo "0";
}
?>
