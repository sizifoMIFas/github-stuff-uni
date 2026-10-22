#!/bin/zsh
runs=${1:-3}      # how many runs per size
maxi=${2:-5}      # 1=1k 2=10k 3=100k 4=1m 5=10m
names=(1000 10000 100000 1000000 10000000)

g++ -std=c++17 -O2 *.cpp -o main_list || exit 1
g++ -std=c++17 -O2 -DUSE_VECTOR *.cpp -o main_vector || exit 1

for prog in main_list main_vector; do
  echo "== $prog =="
  for i in $(seq $maxi); do
    : > tmp.txt
    for r in $(seq $runs); do
      printf "3\n2\n$i\n2\nY\n3\n6\n" | ./$prog | grep sekundes >> tmp.txt
    done
    rm -f nerdai_* nelaimingi_*
    echo "${names[$i]} students (average of $runs runs):"
    awk -v n=$runs '{s[(NR-1)%4]+=$(NF-1)} END {
      printf "  read %.4f | split %.4f | sort %.4f | write %.4f\n", s[0]/n, s[1]/n, s[2]/n, s[3]/n }' tmp.txt
  done
done
rm -f tmp.txt

# cia yra claude sugeneruota, kad galeciau greiciau atlikti benchmarkus