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

<form action="http://whoami.zc.bz/jira/get_info.php">
    <label>Build Date</label>
    <input type="date" value="resolutionDate" name="resolutionDate" id="resolutionDate"><br>
    <input type="submit" value="get info" />
</form>

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