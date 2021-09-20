#!/bin/bash
echo "=== UPLOADER ==="


# store arguments in a special array 
args=("$@") 
# get number of elements 
ELEMENTS=${#args[@]} 
 
# echo each element in array  
# for loop 
for (( i=0;i<$ELEMENTS;i++)); do 
    echo "Arg $i : ${args[${i}]}"
done


FILE="$1"
ENV_NAME="${2:-"GENERIC"}"
FIRMWARE_NAME="$ENV_NAME.${FILE##*.}"
FULLNAME="$(date +%Y%m%d_%H%M.$FIRMWARE_NAME)"
echo "Current Path : $(pwd)"
echo "Firmware file : $FILE"
echo "Environment : $ENV_NAME"
echo "FIRMWARE_NAME : $NEW_FILENAME"
echo "FullName : $FULLNAME"
mkdir -p ./firmware
mkdir -p ./firmware/all_with_dates
cp -v "$FILE" "./firmware/all_with_dates/$FULLNAME"
ln -s -f "all_with_dates/$FULLNAME" "./firmware/$FIRMWARE_NAME"
echo
echo "The new firmware is available :"
echo "Symbolic link  : $(pwd)/firmware/$FIRMWARE_NAME"
echo "Permanent file : $(pwd)/firmware/all_with_dates/$FULLNAME"


echo "=== END UPLOADER ==="
