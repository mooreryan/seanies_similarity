#!/bin/bash
./pairwise_sequence_similarity test_files/test.fa 13 2> /dev/null
diff test_files/test.fa.similarity.txt.expected test_files/test.fa.similarity.txt

if [ $? -eq 0 ]
then
    echo "Test 1: Success!"
else
    echo "Test 1: Fail!"
fi
rm test_files/test.fa.similarity.txt



./pairwise_sequence_similarity test_files/test_all_gaps.fa 13 2> /dev/null

if [ $? -eq 1 ]
then
    echo "Test 2: Success!"
else
    echo "Test 2: Fail!"
fi
rm test_files/test_all_gaps.fa.similarity.txt
