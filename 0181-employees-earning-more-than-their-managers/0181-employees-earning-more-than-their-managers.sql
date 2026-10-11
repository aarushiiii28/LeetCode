# Write your MySQL query statement below
select E.name as Employee
from Employee E JOIN Employee M
ON E.managerID = M.id
where E.salary > M.salary
