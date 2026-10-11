# Write your MySQL query statement below
select distinct P1.email as Email
from Person P1 JOIN Person P2
ON P1.email = P2.email
where P1.id < P2.id
