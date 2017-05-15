# broken-icu-test

This repo was made to test icu issue with non standard currency for locale. It results in reseting precision to default value.

Therefore it is impossible to control it.

Original ticket in icu project:

http://bugs.icu-project.org/trac/ticket/10997


How to run this test:

checkout this repository

run:

`make`

then run:

./test

You should see result like this

Digits: 4
GBP: £123.4500
Digits: 4
EUR: €123.45
Digits: 4


It means that despite the precision set to 4 digits it is reseting that to 2 when switching for EUR currency.

It was tested with version 58.2 without success.

Also attached php file using pecl intl library that has the same issue.
