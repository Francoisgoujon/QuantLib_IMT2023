# Results

### 1

TimeSteps = 10
Samples = 1000000

                        old engine                  non constant                     constant
     kind            NPV       time [s]            NPV       time [s]            NPV       time [s]
 European        4.17073        2.50093        4.17073        2.46779        4.17073       0.43841 (/5.6) 
    Asian       0.729431        2.24142       0.729431        2.22732       0.731168       0.45403 (/5)
  Barrier       0.273727         3.3796       0.273727        3.40945       0.274946       1.36182 (/2.5)

### 2

TimeSteps = 10
Samples = 5000000

                        old engine                  non constant                      constant
     kind            NPV       time [s]            NPV       time [s]            NPV       time [s]
 European        4.16733        12.6165        4.16733        12.4293        4.16733        2.21572 (/5.6)
    Asian       0.728807        11.4614       0.728807         11.335       0.730542         2.2288 (/5)
  Barrier       0.274119        17.3082       0.274119        17.4435       0.275338        6.84327 (/2.5)

### 3

TimeSteps = 50
Samples = 1000000

                        old engine                  non constant                      constant
     kind            NPV       time [s]            NPV       time [s]            NPV       time [s] 
 European        4.16453        11.7593        4.16453        11.6482        4.16453        1.90613 (/6.1)
    Asian       0.729431        2.28122       0.729431        2.28452       0.731168        0.45562 (/5)
  Barrier       0.274529         16.016       0.274529        16.1783       0.275829        6.53073 (/2.5)


- We can see that our modifications did not corrupt the pricer as we get NPV values almost identical to the ones with the non constant pricer.
- We can also clearly see the improvement in execution time.