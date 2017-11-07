<html>
<head>
	<title> Result </title>
	<style>
		table, th, td {
			border: 1px solid black;
			border-collapse: collapse;
			padding: 5px;
		}
	</style>
</head>
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