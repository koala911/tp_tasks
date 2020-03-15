dir_to_backup=$1
mkdir $3
backup_dir=$(pwd)/$3
cd $dir_to_backup
ext=$2
dfs () {
  names=$(ls)
  for name in $names
  do
    if [ -d ./$name ] 
    then 
      cd $name
      dfs
      cd ..
    else
      if [[ $name == *.$ext ]] && [ -f ./$name ]
      then
        new_file_name=$name
        k=1  
        while [ -f $backup_dir/$new_file_name ]
        do  
          new_file_name=$k$name
          ((k++))
        done
        cp $name $backup_dir/$new_file_name
      fi
    fi
  done
}
dfs
cd $backup_dir
cd ..
tar -zcf $4 $3 2> /dev/null
echo "done"