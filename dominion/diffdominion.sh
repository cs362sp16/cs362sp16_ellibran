#diffdominion

#cleanup
rm -f testdominion1.txt testdominion2.txt differential.txt

#getting seed
echo -n "Enter Seed: "
read seed

#making
make all
make testdominion

#changing directory to the second one
cd ../../dominion/

#making
make all
make testdom

clear

#returning to begining directory
cd ../../cs362sp16_ellibran/dominion/

testdominion $seed > testdominion1.txt
../../dominion/testdom $seed > ../../cs362sp16_ellibran/dominion/testdominion2.txt

diff --suppress-common-lines testdominion1.txt testdominion2.txt > diff.txt

if [[ -s diffresult ]]; then
	echo "TEST FAILED"
	cat diff.txt
else
	echo "TEST SUCCESS"
fi ; 