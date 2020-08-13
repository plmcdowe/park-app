<?php
$con=mysqli_connect("127.0.0.1","user_name", "pass_word", "parking", 3306);

$count = $_GET['count'];
$num = (int)$count;


$sql="UPDATE garages SET count = '$num' WHERE id = '1'";

if (!mysqli_query($con,$sql))
{ die('Error: ' . mysqli_error($con)); }

mysqli_close($conn);
?>
