SELECT n1, n2, n1*n2 FROM
    (SELECT value AS n1 FROM numbers)
    JOIN
    (SELECT value AS n2 FROM numbers)
    WHERE n1 + n2 = 2020;
