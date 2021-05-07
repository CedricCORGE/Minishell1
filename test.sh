#!/bin/sh

cat <<EOF > list_cmd
  ls -l /bin
  sleep 2
  /bin/pwd
EOF

cat list_cmd | tcsh 2>&1 > tcsh.result
cat list_cmd | ./mysh 2>&1 > mysh.result

diff tcsh.result mysh.result
if [ $? -eq 0 ]
then
    echo "Résultat identique \0/"
else
    echo "Raté !"
fi