DROP TABLE IF EXISTS numbers;
CREATE TABLE numbers(value INTEGER);
.mode csv
.import input.txt numbers
