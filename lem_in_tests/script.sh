working()
{
	for map in "directlink2end" "simple" "roundmap" "input2" "duplicatepipe1" "input3" "underflow" "invalidcommand" "comments" "diamond" "simple1" "overflow" "loop" "hardmap" "cobmap" "map10" "testbug" "pentagram" "input1" "in0" "map14" "map42" "input0" "maptest" "triforce" "shortest" "test" "Chloe" "toile" "multiplewaysmap" "europe_utf" "42" "bmap" "big" "mmkr2";
	do
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
done;
}


unvalid()
{
	for map in "empty" "no_rooms" "startisend" "nopath" "no_tubes" "multiends" "nostart" "noend" "no_ants" "noants" "bad_rooms" "invalidcommand1" "whitespaces" "illegalname" "loop1" "test2commentary" "comments2" "map4" "simple2" "test1" "map3" "input4" "haaaaaaaaaaaaaaaaaaaardtest";
	do
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
	done;
}


printf "Working or Unworking maps (w/u) ? ";
read response;

if [ $response = "u" ]
	then	unvalid

elif [ $response = "w" ]
	then	working
else
	exit
fi

exit;
