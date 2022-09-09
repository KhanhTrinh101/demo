** Tổng quan:
	Hệ thống cài đặt trên thiết bị AVN của ô tô được chia thành các chức năng theo các đối tượng khác nhau 
	theo vai trò và trách nhiệm trong công việc. Chương trình này sẽ cài đặt 1 vài thông số trên 3 chức 
	năng Display, Sound, General.

	- Display: Quản lý các cài đặt liên quan đến việc hiển thị trên màn hình. Trong đó có rất nhiều các chức
	năng nhỏ liên quan đến display bao gồm: light level, screen light level, taplo light level.

	- Sound: Phụ trách thực hiện các công việc cài đặt về hệ thống âm thanh. Trên ô tô hệ thống âm thanh khá 
	phức tạp và có nhiều thành phần nên trong chương trình nay chỉ bao gồm : Media volume level, Call volume 
	level, Navigation volume level, Notification volume level.

	- General: Gồm các cài đặt chung cho hệ thống AVN như common key, thời gian, ngôn ngữ và các chức năng 
	chung khác. Trong chương trình này sẽ chỉ thực hiện các công việc cài đặt cho hai chức năng chính đó là 
	cài đặt timezone và cài đặt language.

	- Một chiếc xe sẽ có đầy đủ cài đặt của cả Display, Sound, General. Tất cả các đối tượng trên đều có
	thông tin chung cần quản lý là Tên xe, mã số cá nhân, email người sử dụng, ODO, thông tin km cần đến để 
	bảo dưỡng xe.

** Chức năng:
	Chương trình đọc dữ liệu của xe được lưu trong file data.txt sau đó lưu vào trong ModelData trên chương 
	trình từ ModelData ta có thể in các dữ liệu được lưu bên trong ra và có thể thay đổi dữ liệu bên trong 
	Model. Sau khi kết chương trình dữ liệu xe trong ModelData sẽ được ghi đè lên file data.txt.

** Luồng đầu vào của chương trình:
	- Thông tin của list timezone, list language sẽ được đọc từ file timezone.txt, language.txt.
	- Thông tin dữ liệu (info user, info car) sẽ được đọc từ file data.txt 
	- Các thông tin sau khi đọc sẽ được quản lý bên thông qua các class: carOwner, display, sound, general.
		+ Class carOwner sẽ quản lý thông tin: Owner name, email, personalkey, odo, remind service.
		+ Class display sẽ quản lý thông tin: light level, screen light level, taplo light level.
		+ Class sound sẽ quản lý thông tin: media volume level, call volume level, navigation volume level,
		notification volume level.
		+ Class general sẽ quản lý thông tin: timezone, language.
	- Các class trên sẽ được quản lý bởi class carsetting tức là tạo các đối tượng display, sound, general
	bên trong class carsetting, class carsetting chỉ kế thừa từ class carOwner và độc lập với các class khác.
	- Sử dụng linker List để làm Model lưu trữ dữ liệu là các đối tượng carsetting.

** Thay đổi dữ liệu trong Model trên chương trình:
	- Thêm một xe mới vào model: ta tạo một đối tượng carsetting mới và nhập dữ liệu cho nó sau đó 
	thêm đối tượng đó vào model.
	- Thay đổi thông tin của một xe mà ta muốn: ta cũng sẽ tạo một đối tượng carsetting mới sau đó nhập
	mã số cá nhân trùng với mã số cá nhân của xe mà ta muốn thay đổi thông tin. Các thông tin sẽ được ghi
	đè lên xe có mã số cá nhân đây.
	- Các thông tin cài đặt khi nhập vào sẽ được valiudate.

** In thông tin ra từ modelData
	- Thông tin được in ra theo hai cách: in theo mã số cá nhân, in theo tên chủ xe.
	- Sau khi chọn cách in thì tiếp tục chọn in theo display, sound, general, all. Tức là in thông tin của
	của riêng đối tượng đấy và các đối tượng đều kế thừa từ class carOwner nên sẽ in luôn thông tin trong
	carOwner.

** valiudate:
	- checkNumber: bool. Kiểm tra ký tự nhập vào có phải là số không, true nếu là số, ngược lại là false.
	- inputOneNumber: int. Nhập vào một số. Số nhập vào là một số số nguyên dương.
	- inputPersonalkey: string. Nhập vào một dãy số. Dãy số nhập vào là một dãy số nguyên dương không chứa ký tự.
	- CheckEmail: bool. Kiểm tra email nhập vào phải theo format abc@gmail.com
	- explode: vector<string>. Khi đọc dữ liệu xe từ file data.txt thì các dữ liệu được ghi trên một hàng và
	mỗi một đối tượng cách nhau bởi dấu '/', dùng hàm explode để tách dữ liệu ra và đưa vào các class tương
	ứng.