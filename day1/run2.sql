SELECT n1, n2, n3, n1*n2*n3 FROM
    (SELECT value AS n1 FROM numbers)
    JOIN
    (SELECT value AS n2 FROM numbers)
    JOIN
    (SELECT value AS n3 FROM numbers)
    WHERE n1 + n2 + n3 = 2020;
