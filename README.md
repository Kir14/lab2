# lab2
Написать программы для организации двух процессов MainProc и Daughter, предназначенные для корректировки данных в бинарном файле.
MainProc:
1. Открывает файл с данными и выводит их на экран.
2. Запрашивает номер структуры, которая должна быть изменена.
3. Запускает процесс Daughter в который через параметры командной строки передается информация о необходимой корректировке.
4. Ожидает завершения работы процесса Daughter.
5. Выводит откорректированные данные из файла на экран.
6. Завершает свою работу.
Daughter:
1. Выводит на экран информацию, полученную через командную строку.
2. Вносит необходимые изменения в файл.
3. Завершает свою работу.
