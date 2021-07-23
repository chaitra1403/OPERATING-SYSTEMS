while :
do
echo '************************************************'
echo 'MENU'
echo '1.Count the files only with read permission for all users'
echo '2.display current date with *'
echo '3.display directory/file with formatted output'
echo '4.convert to uppercase and store to other file'
echo '************************************************'
echo 'Enter your choice \n'
read ch

case $ch in
1)
echo 'PART1'
ls -l|grep r--r--r-- -c;;

2)
echo 'PART2'
set -- `date`
cal -h | grep $3 | sed "s/$3/"*"/";;

3)
echo 'PART3'
echo 'Enter the file'
read  fname
if [ -f $fname ]
then
set -- `ls -l $fname`
echo "file permission" $1
echo "link" $2
echo "filename" $9
echo "current date" $7
else
echo "file not found"
fi;;

4)
echo 'PART4'
echo 'Entre the source file'
read source
echo 'Enter destination file'
read dest
cat $source|head -v|tr '[a-z]' '[A-Z]'>$dest
cat $dest;;

*)
echo 'Invalid  choice';;
esac
done

