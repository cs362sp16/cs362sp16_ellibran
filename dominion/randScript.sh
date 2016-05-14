# Script

echo "Running: randomtestcard1"
echo "Seed: 42"
echo "Times: 1000"
echo "Output: Disabled"
rm -f randomtestcard1.out
randomtestcard1 42 1000 0 >> randomtestcard1.out
gcov dominion.c >> randomtestcard1.out

echo "------------------------"

echo "Running: randomtestcard1"
echo "Seed: 42"
echo "Times: 1000"
echo "Output: Disabled"
rm -f randomtestcard2.out
randomtestcard2 42 1000 0 >> randomtestcard2.out
gcov dominion.c >> randomtestcard2.out

echo "------------------------"

echo "Running: randomtestcard1"
echo "Seed: 42"
echo "Times: 1000"
echo "Output: Disabled"
rm -f randomtestadventurer.out
randomtestadventurer 42 1000 0 >> randomtestadventurer.out
gcov dominion.c >> randomtestadventurer.out