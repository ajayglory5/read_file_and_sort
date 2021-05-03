# read_file_and_sort
This is a C++ program, that uses names.txt, a text file containing over 5000 first names, and sort it into alphabetical order.
Then works out the alphabetical value for each name and multiplies this value by its position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So COLIN would obtain a score of 938 x 53 = 49714.

Finally, it calculates the total sum of all the name scores in the file.

# steps to compile and run
* Download the package using the command:
```
git clone https://github.com/ajayglory5/read_file_and_sort.git
```

* Go inside the repository, if required:
```
cd read_file_and_sort/
```

* Now create a temporary build directorsy to compile. Execute the following command:
```
mkdir build
cd build
cmake ../
make
```

* After this successful compilation, execute the binaries to see the output. Commands:
```
./src/exercise
```
This should give the output as:
```
Started to parse the file...
The total sum of all name scores is 871198282
```

* To execute the unit testcases, run the following command:
```
./test/exercise_test
```
This should give the output as:
```
[==========] Running 6 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from fileRead
[ RUN      ] fileRead.expectError
[       OK ] fileRead.expectError (2 ms)
[ RUN      ] fileRead.expectSuccess
[       OK ] fileRead.expectSuccess (4 ms)
[----------] 2 tests from fileRead (7 ms total)

[----------] 1 test from sortNames
[ RUN      ] sortNames.result
[       OK ] sortNames.result (1 ms)
[----------] 1 test from sortNames (1 ms total)

[----------] 1 test from scoreCalculation
[ RUN      ] scoreCalculation.name
[       OK ] scoreCalculation.name (2 ms)
[----------] 1 test from scoreCalculation (2 ms total)

[----------] 2 tests from totalScoreCalculation
[ RUN      ] totalScoreCalculation.test_data_1
[       OK ] totalScoreCalculation.test_data_1 (2 ms)
[ RUN      ] totalScoreCalculation.names
[       OK ] totalScoreCalculation.names (10 ms)
[----------] 2 tests from totalScoreCalculation (12 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 4 test suites ran. (25 ms total)
[  PASSED  ] 6 tests.
```
