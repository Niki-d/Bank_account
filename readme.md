В данном работе представлено два класса: account и Extra_account. Причем второй публично наследуется из первого, 
с некоторыми доп.возможностями.
Класс предок имеет методы, которые позволяют пополнить его счёт, снять деньги со счёта. Причем нельзя снять больше,
чем денег на счету. Класс потомок же наследует методы предка, к тому же реализована возможность уйти в минус на определенное
числовое значение (кредит). Часть занимаемых денег облагается процентом. Процент берется при получении кредита от занимаемой суммы.
Существует сумма, больше которой нельзя получить кредит. Если пользователь счёта уже взял кредит, то он может взять ещё,
но при условие, что сумма ( (прошлий кредит+проценты)+ (новый кредит+проценты) ) всё так же не превышает той самой суммы, 
больше которой нельзя получить кредит. Если пользователь счёта попытается запросить большую сумму, то операция будет
отменена или его счёт не изменится.

Базовый класс account представляет собой банковский счёт, который хранит поля: 
1) ID - однозначный идентификационный номер пользователя счёта;
2) first_name и second_name  - имя и фамилия соответственно;
3) balance - кол-во денег на счету пользователя счёта.
Есть ещё одно поле id, которое является статическим и через которое реализован простейший генератор ID.

Публичные методы:
1) static int get() - статический метод, который возвращает кол-во созданных объектов(пользователей счетов);
2) get- и set- методы к полям класса;
3) add_balance(int sum) - метод, позволяющий добавить сумму m к счёту;
4) negative_add_balance(int sum) - метод, позволяющий снять некоторую сумму m с счёта. Данный метод имеет ключевое
слово virtual, т.к. класс потомок будет его переопределять;
5) Два конструктора. Первый обнуляет все поля, кроме поля ID. Второй заполняет поля по передаваемым аргументам.


Приватные поля класса наследника Extra_account:
1) MAX - поле, определяющее сумму, больше которой нельзя получить кредит;
2) percent - процент кредитования.

Публичные методы Extra_account:
1) Два конструктора;
2) Переопределенный метод negative_add_balance(int sum), который позволяет уходить в минус.



main.cpp:
1) Создан объект(пользовательский счёт) num_1 класса account;
2) Объект num_1 положил дополнительно на свой счёт 2000;
3) Данные о счёте num_1 выведены на консоль;
4) Создан объект(пользовательский счёт) num_2 класса Extra_account;
5) Объект num_2 положил допольнительно на свой счёт 3000;
6) Данные о счёте num_2 выведены на консоль;
7) Владелец счёта num_1 попытался снять 13000. В итоге отказ. Счёт выведен на консоль и не изменился;
8) Владелец счёта num_2 хочеть снять 14000, но у него нет столько денег. Банк предоставляет ему кредит с процентами. Счёт выведен на консоль;
9) Владелец счёта num_2 хочеть снять ещё 1000, т.к. лимит не превышен, банк предоставляет кредит с новыми процентами. Счёт выведен на консоль;
10) Владелец счёта num_2 хочеть снять ещё 1000. Отказ в операции. Счёт выведен на консоль;
11) На консоль выведено кол-во объектов.