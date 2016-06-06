import subprocess
import string
import os
import decimal

num_failed = 0
numTests = 1000
failing_tests = []
passing_tests = []
f = open('tmp.txt', 'w')


#########################################
#Searches through and finds failing tests
#########################################
subprocess.call(["make", "testdominion"], stdout = f)
for arg in range(1, numTests + 1):
	returnValue = subprocess.call(["testdominion", str(arg)])
	if (returnValue != 0):
		num_failed = num_failed + 1
		failing_tests.append(arg)
		
	else:
		passing_tests.append(arg)

print str(num_failed) + " out of " + str(numTests) + " tests failed\n"







#Run the failing test cases
subprocess.call(["make", "clean"], stdout = f)
subprocess.call(["make", "testdominion"], stdout = f)

for arg in failing_tests:
	returnValue = subprocess.call(["testdominion", str(arg), "0"])
	if (returnValue == 0):
		print "\n\nEncountered unexpected passing test case\n"
		
print "failing test coverage:"
returnValue = subprocess.call(["gcov", "dominion.c"])
os.rename("dominion.c.gcov", "failed_tests.out")






#Run the passing test cases
subprocess.call(["make", "clean"], stdout = f)
subprocess.call(["make", "testdominion"], stdout = f)

for arg in passing_tests:
	returnValue = subprocess.call(["testdominion", str(arg), "0"])
	if (returnValue != 0):
		print "\n\nEncountered unexpected failing test case\n"
		
print "passing test coverage:"
returnValue = subprocess.call(["gcov", "dominion.c"])
os.rename("dominion.c.gcov", "passed_tests.out")


f.close()





# Examine coverage
failed_tests = open('failed_tests.out', 'r')
passed_tests = open('passed_tests.out', 'r')
tarantula = open('tarantula.out', 'w')

tarantula.write("suspiciousness\n")

s_list = []

for failed in failed_tests:
	passed = passed_tests.readline()
	
	
	f = failed.split(':', 2)[0]
	p = passed.split(':', 2)[0]
	line_number = passed.split(':', 2)[1]
	
	if (f.count('-') > 0 or f.count('#') > 0):
		f = '0'
	if (p.count('-') > 0 or p.count('#') > 0):
		p = '0'
	
	f = decimal.Decimal(f)
	p = decimal.Decimal(p)

	
	#Compute suspiciousness
	total_passed = numTests - num_failed
	s = -1
	if ((p / total_passed  +  f / num_failed) != 0):
		s = decimal.Decimal((f / num_failed) / (p / total_passed  +  f / num_failed))
		s_list.append((str(round(s, 3)), line_number))

	tarantula.write(str(round(s, 3)) + "\t" + str(failed))
	
	
	
failed_tests.close()
passed_tests.close()
tarantula.close()

s_list.sort(reverse = True)

print "Fault localization complete!"
print "Here are the ten most suspicious lines in your program: \n"
print "Suspiciousness\tLine number"
for i in range(10):
	print s_list[i][0] +  "\t\t" + s_list[i][1]
print "\n\nSee tarantula.out for an annotated annotated version of dominion.c\n"