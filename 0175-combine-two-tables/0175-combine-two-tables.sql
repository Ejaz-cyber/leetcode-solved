# Write your MySQL query statement below

select 
p.firstname, p.lastname,
a.city, a.state 
from person p
LEFT JOIN address a ON p.personid = a.personid;