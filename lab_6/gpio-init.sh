FILEPATH='/sys/class/gpio'
echo 13 > $FILEPATH/unexport 2>/dev/null
echo 10 > $FILEPATH/unexport 2>/dev/null
echo 11 > $FILEPATH/unexport 2>/dev/null
echo 12 > $FILEPATH/unexport 2>/dev/null
echo 0 > $FILEPATH/unexport 2>/dev/null
echo 13 > $FILEPATH/export
echo 10 > $FILEPATH/export
echo 11 > $FILEPATH/export
echo 12 > $FILEPATH/export
echo 0 > $FILEPATH/export
echo out > $FILEPATH/gpio13/direction
echo out > $FILEPATH/gpio10/direction
echo out > $FILEPATH/gpio11/direction
echo out > $FILEPATH/gpio12/direction
echo out > $FILEPATH/gpio0/direction
