git pull -v
clear
echo ===================
echo -e "上次tag:" & cat ./version.txt
echo ===================
# 提示用户输入 tag 名称
echo "tag name:"
read name
echo $name > ./version.txt
#
# # 提示用户输入 commit 信息
echo "commit:"
read commit
git add . -v
git commit -v -m "$commit"
git push -v

#
# # 创建标签
git tag -a "$name" -m "$commit"
#
git push --tags -v
