<html>
<body>

Platform <?php echo $_GET["platform"]; ?><br>
Model Name  <?php echo $_GET["model"]; ?><br>
Resolution Date <?php echo $_GET["resolutionDate"]; ?><br><br>

<?php $command = 'python get_info.py ' . $_GET["resolutionDate"];
exec($command, $output);

for($x = 0; $x < count($output); $x++) {
	echo $output[$x];
	echo "<br>";
}
?>

</body>
</html>