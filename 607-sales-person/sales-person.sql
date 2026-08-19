# Write your MySQL query statement below
select sp.name
from SalesPerson sp
where not exists (
    select 1
    from Orders o
    join Company c
    on o.com_id= c.com_id
    where o.sales_id= sp.sales_id
    and c.name= 'RED'
)