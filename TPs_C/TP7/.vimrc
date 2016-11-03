set number
set mouse=a
set cursorline
imap <F8> <Esc>:w<CR>:!clear && gcc -Wall -Werror -Wextra % && ./a.out<CR>
map <F8> :w<CR>:!clear && gcc -Wall -Werror -Wextra % && ./a.out<CR>
imap <F7> <Esc>:w<CR>:!clear && ./% test1 test2 test3 test4<CR>
map <F7> :w<CR>:!clear && ./% test1 test2 test3<CR>
