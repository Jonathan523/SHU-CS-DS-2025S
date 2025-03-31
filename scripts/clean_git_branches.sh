git fetch -p
git remote prune origin
git branch -vv | grep 'gone\]' | awk '{print $1}' | xargs -n 1 git branch -D