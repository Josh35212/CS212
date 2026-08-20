print_factors=0
for i in range(2, 1000):
   the_number=i
   num_factors=0
   for j in range(2, i-1):
      if (the_number % j == 0):
          num_factors=num_factors+1
          while (the_number % j == 0):
              the_number=the_number/j
   if (num_factors == 3):
      print "%d has three factors" %(i)
      if (print_factors):
        the_number=i
        num_factors=0
        print "%d = " %(the_number)
        for j in range(2, i-1):
         if (the_number % j == 0):
             num_factors=num_factors+1
             num_instances=0
             while (the_number % j == 0):
                 num_instances=num_instances+1
                 the_number=the_number/j
             if (num_instances == 1):
                 print "\t%d" %(j)
             else:
                 print "\t%d^%d" %(j, num_instances)
