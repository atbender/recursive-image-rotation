# atbender
# 22/03/2021

# load program on interpreter with "run recursive_rotation.h"
# run function with "recursive_rotate()"

# recursive rotation of image
function [img] = rotate(img, x, y, width, idx)
	global image_id;
	width = floor(width / 2);

	temp = img(y:y + width - 1, x:x + width -1);

	img(y:y + width - 1, x:x + width - 1) = img(y + width:y + 2 * width - 1, x:x + width - 1);
	img(y + width:y + 2 * width -1, x:x + width -1) = img(y + width:y + 2 * width -1, x + width:x + 2 * width -1);
	img(y + width:y + 2 * width - 1, x + width:x + 2 * width - 1) = img(y:y + width - 1, x + width:x + 2 * width - 1);
	img(y:y + width - 1, x + width:x + 2 * width -1) = temp;

	if width > 1
		img = rotate(img, x, y, width, idx + 1);
		img = rotate(img, x + width, y, width, idx + 1);
		img = rotate(img, x + width, y + width, width, idx + 1);
		img = rotate(img, x, y + width, width, idx + 1);

		string = cstrcat('recursion depth: ', num2str(idx));
		disp(string);

		string = cstrcat('lenas/lena_', num2str(image_id), '.bmp');
		image_id = image_id + 1;
		imwrite(img, string);
	end
	img;
end

global image_id = 1;

function recursive_rotate()
	global image_id = 1;
	img = imread('lena_color.bmp');
	img = img(221:284, 221:284);

	idx = 1;

	string = cstrcat('lenas/lena_', num2str(image_id), '(start).bmp');
	image_id = image_id + 1;
	imwrite(img, string);

	img = rotate(img, 1, 1, 64, idx);

	string = cstrcat('lenas/lena_', num2str(image_id), '(final).bmp');
	image_id = image_id + 1;
	imwrite(img, string);

	imshow(img);
	waitfor(gcf);
	disp('done!');
end