# Hướng dẫn sử dụng git

## Tạo nhánh mới trên repo

<ol>
    <li>git clone ${remote url} </li>
    <li>git checkout -b ${tên nhánh}</li>
    <li>git push -u origin ${tên nhánh}</li>
</ol>

---

## Push code

<ol>
    <li>git add .</li>
    <li>git commit -m "Mô tả về commit"</li>
    <li>git push</li>
</ol>

## Pull code

<ol>
    <li>git checkout develop</li>
    <li>git pull</li>
</ol>



## Merge code
<ol>
    <li>git add . //lưu các file</li>
    <li>git stash //tạm thời lưu trữ việc đang làm để chuyển sang làm trên 1 branch khác, Git sẽ lưu trữ các thay đổi đó vào một vùng tạm thời được gọi là stash stack</li>
    <li>git checkout a //chuyển sang branch a</li>
    <li>git merge b //merge branch b vào branch a</li>
    <li>git stash pop //áp dụng lại các thay đổi được lưu trữ trong stash stack và xóa chúng khỏi stash stack.</li>
</ol>

## Commands
<ol>
    <li>git add . //lưu các file</li>
    <li>git stash //tạm thời lưu trữ việc đang làm để chuyển sang làm trên 1 branch khác, Git sẽ lưu trữ các thay đổi đó vào một vùng tạm thời được gọi là stash stack</li>
    <li>git checkout a //chuyển sang branch a</li>
    <li>git merge b //merge branch b vào branch a</li>
    <li>git stash pop //áp dụng lại các thay đổi được lưu trữ trong stash stack và xóa chúng khỏi stash stack.</li>
</ol>

## Commands
<ol>
	<li>git init //tạo 1 repo</li>
	<li>git status //kiểm tra trạng thái</li> 
	<li>git add //lưu lại thời điểm của dự án</li>
	<li>git add . // lưu lại tất cả</li>
	<li>git reset //reset lại các file cần lưu</li> 
	<li>git commit -m 'branch name' //chính thức lưu</li> 
	<li>git log //kiểm tra thời điểm commit</li>
	<li>git log --oneline //kiểm tra trên cùng 1 dòng</li>
	<li>git checkout id // trở lại thời điểm commit</li>
	<li>git checkout {branch name} // trở lại thời điểm commit </li>
	<li>git checkout -b {branch name} //tạo 1 branch mới</li>
 	<li>git merge {branch name} //gộp branch</li> 
	<li>git branch -d {branch name} //xóa branch</li> 
	<li>git push //đẩy code lên repo</li>
	<li>git push -u origin {branch name} //tạo ra 1 branch trên github</li>
</ol>