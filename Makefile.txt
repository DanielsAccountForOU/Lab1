CC=g++ -Wall -std=c++11

# Note: Requires you to make a file with a main function to work properly
make_lab: MyTime.cc MyTime.h
	$(CC) *.cc -o lab.out

# Multiple ways to run tests in case of spelling differences
run-test: run_tests
run-tests: run_tests
run_test: run_tests
run_tests: MyTime.cc
	$(CC) $^ _TEST/TEST_cases.cc -o ./_TEST/test.out
	./_TEST/test.out

clean:
	rm -f _TEST/*.out