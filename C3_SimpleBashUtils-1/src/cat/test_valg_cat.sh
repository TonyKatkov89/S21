#!/ bin / bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
VALG_RES=""
TEST_FILE="bytes.txt"
echo "" > valg_log.txt

for var in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
do
          TEST1="$var $TEST_FILE"
          echo "$TEST1"
          valgrind --tool=memcheck --leak-check=yes ./s21_cat $TEST1 > s21_cat_valg.txt 2>&1
          VALG_RES="$(sed -n -e 's/^.*\(ERROR SUMMARY\)/\1/p' s21_cat_valg.txt)"
#echo "$VALG_RES"
          if [ "$VALG_RES" = "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" ]
            then
              COUNTER_SUCCESS=$(( $COUNTER_SUCCESS + 1 ))
            else
              echo "$TEST1" >> valg_log.txt
              COUNTER_FAIL=$(( $COUNTER_FAIL + 1 ))
          fi
          rm s21_cat_valg.txt
done

for var in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
do
  for var2 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
  do
        if [ $var != $var2 ]
        then
          TEST1="$var $var2 $TEST_FILE"
          echo "$TEST1"
          valgrind --tool=memcheck --leak-check=yes ./s21_cat $TEST1 > s21_cat_valg.txt 2>&1
          VALG_RES="$(sed -n -e 's/^.*\(ERROR SUMMARY\)/\1/p' s21_cat_valg.txt)"
#echo "$VALG_RES"
          if [ "$VALG_RES" = "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" ]
            then
              COUNTER_SUCCESS=$(( $COUNTER_SUCCESS + 1 ))
            else
              echo "$TEST1" >> valg_log.txt
              COUNTER_FAIL=$(( $COUNTER_FAIL + 1 ))
          fi
          rm s21_cat_valg.txt
        fi
  done
done

for var in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
do
  for var2 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
  do
      for var3 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
      do
        if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ]
        then
          TEST1="$var $var2 $var3 $TEST_FILE"
          echo "$TEST1"
          valgrind --tool=memcheck --leak-check=yes ./s21_cat $TEST1 > s21_cat_valg.txt 2>&1
          VALG_RES="$(sed -n -e 's/^.*\(ERROR SUMMARY\)/\1/p' s21_cat_valg.txt)"
#echo "$VALG_RES"
          if [ "$VALG_RES" = "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" ]
            then
              COUNTER_SUCCESS=$(( $COUNTER_SUCCESS + 1 ))
            else
              echo "$TEST1" >> valg_log.txt
              COUNTER_FAIL=$(( $COUNTER_FAIL + 1 ))
          fi
          rm s21_cat_valg.txt
        fi
      done
  done
done

for var in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
do
  for var2 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
  do
      for var3 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
      do
          for var4 in -b -e -n -s -t #-v -E -T --number-nonblank --number --squeeze-blank
          do
            if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ]
            then
              TEST1="$var $var2 $var3 $var4 $TEST_FILE"
              echo "$TEST1"
              valgrind --tool=memcheck --leak-check=yes ./s21_cat $TEST1 > s21_cat_valg.txt 2>&1
              VALG_RES="$(sed -n -e 's/^.*\(ERROR SUMMARY\)/\1/p' s21_cat_valg.txt)"
#echo "$VALG_RES"
              if [ "$VALG_RES" = "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" ]
                then
                  COUNTER_SUCCESS=$(( $COUNTER_SUCCESS + 1 ))
                else
                  echo "$TEST1" >> valg_log.txt
                  COUNTER_FAIL=$(( $COUNTER_FAIL + 1 ))
              fi
              rm s21_cat_valg.txt
            fi
          done
      done
  done
done

echo -e "\e[31mFAIL: $COUNTER_FAIL\e[0m"
echo -e "\e[32mSUCCESS: $COUNTER_SUCCESS\e[0m"