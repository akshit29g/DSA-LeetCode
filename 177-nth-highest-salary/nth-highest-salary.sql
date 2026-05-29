CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e1.salary
      FROM Employee e1
      Where N-1 = (
        SELECT COUNT(DISTINCT e2.salary)
        FROM EMPLOYEE e2
        WHERE e2.salary>e1.salary
      ) 
  );
END