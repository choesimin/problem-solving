git add *.cc *.sh
git add -u
git commit -m "Update"
git push origin master
git clean -f

# settings.json의 code-runner.executorMap.cpp에 '-std=c++17' 추가