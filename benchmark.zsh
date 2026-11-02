#!/bin/zsh

RUNS=${RUNS:-5}     # how many times to repeat each test (5 unless you say otherwise)
SORT=1              # 1 = sort by name

NUMERIAI=(2 3 4)                  # file number in the "provided files" menu
DYDZIAI=(10000 100000 1000000)    # how many students are in that file

echo "programa      studentu  strat  skaitymas  skirstymas  rikiavimas  rasymas  suma" | tee benchmark_laikai.txt

for programa in main_list main_vector; do
    for i in 1 2 3; do
        for strategija in 1 2 3; do

            # vector + strategy 2 + 1M takes ~9 minutes per run, so skip it
            if [[ $programa == main_vector && $strategija == 2 && $i == 3 ]]; then
                echo "$programa  ${DYDZIAI[$i]}  strat $strategija  PRALEISTA (per letas)" | tee -a benchmark_laikai.txt
                continue
            fi

            rm -f laikai.tmp

            for k in $(seq 1 $RUNS); do
                printf '3\n1\n%s\n2\nY\n%s\n%s\n6\n' ${NUMERIAI[$i]} $SORT $strategija | ./$programa | head -c 200000 > izvestis.tmp

                if [[ $(grep -c "per:" izvestis.tmp) -ne 4 ]]; then
                    echo "KLAIDA: $programa ${DYDZIAI[$i]} strat $strategija, patikrink izvestis.tmp"
                    exit 1
                fi

                grep "per:" izvestis.tmp | awk '{printf "%s ", $4} END {print ""}' >> laikai.tmp
            done

            suma=$(cat nerdai_studentai${DYDZIAI[$i]}.txt nelaimingi_studentai${DYDZIAI[$i]}.txt | shasum | cut -c1-8)

            awk -v p=$programa -v n=${DYDZIAI[$i]} -v s=$strategija -v m=$suma \
                '{a+=$1; b+=$2; c+=$3; d+=$4} END {printf "%-12s %8d  %5d  %.5f  %.5f  %.5f  %.5f  %s\n", p, n, s, a/NR, b/NR, c/NR, d/NR, m}' laikai.tmp | tee -a benchmark_laikai.txt
        done
    done
done

rm -f laikai.tmp izvestis.tmp