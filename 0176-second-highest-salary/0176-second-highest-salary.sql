# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < ( ## woh max salary joh first max nikalne ka baad max ho
    SELECT MAX(salary)
    FROM Employee
);