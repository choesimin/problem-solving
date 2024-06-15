git status
git add *.cc
git commit -m "Update"
git push origin master
git clean -f
git status

# settings.json의 code-runner.executorMap.cpp에 '-std=c++17' 추가