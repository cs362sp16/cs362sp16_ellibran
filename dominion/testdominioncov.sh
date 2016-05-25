clear

rm -f testdominion.out tmp.out
testdominion 42 >> tmp.out
gcov dominion.c >> testdominion.out

echo "Cat: testdominion.out"
cat testdominion.out