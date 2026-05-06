# Write your MySQL query statement below
select name as Customers
from Customers
left Join Orders on Customers.id=Orders.customerId
where Orders.customerId is NULL