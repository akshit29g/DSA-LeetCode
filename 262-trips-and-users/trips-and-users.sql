# Write your MySQL query statement below
select t.request_at as Day,
round(
    sum(case 
        when t.status!='completed' then 1
        else 0
        end)/count(*),
    2
) as 'Cancellation Rate'
from Trips t
join Users c
on t.client_id=c.users_id
join Users d
on t.driver_id=d.users_id
where c.banned='No'
and d.banned= 'No'
and t.request_at between '2013-10-01' AND '2013-10-03'
group by t.request_at
