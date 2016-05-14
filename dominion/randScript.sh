# Script

echo "Running: randomtestcard1"
echo "Seed: 42"
echo "Times: 1000"
echo "Output: Disabled"
rm -f randomtestcard1.out
randomtestcard1 42 1000 0 >> randomtestcard1.out
gcov dominion.c >> randomtestcard1.out