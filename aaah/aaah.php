<?
	fscanf(STDIN, '%s', $line1);
  fscanf(STDIN, '%s', $line2);
	fprintf(STDOUT, "%s\n", strlen($line1) < strlen($line2) ? "no" : "go");
?>
