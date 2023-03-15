# Results

### 1

TimeSteps = 10
Samples = 1000000

                              old engine                  non constant                      constant      
           kind            NPV       time [s]            NPV       time [s]            NPV       time [s] 
       European        4.17073        2.45214        4.17073        2.44129        4.17073        2.41864 
          Asian       0.729431        2.25492       0.729431         2.2346       0.729431        2.23255 
        Barrier       0.273727        3.76168       0.273727        3.55269       0.273727        3.45138 

### 2

TimeSteps = 10
Samples = 5000000

                              old engine                  non constant                      constant      
           kind            NPV       time [s]            NPV       time [s]            NPV       time [s]
       European        4.16733        12.5842        4.16733        12.3776        4.16733         12.402
          Asian       0.728807        11.3288       0.728807        11.3262       0.728807        11.3974
        Barrier       0.274119        17.1354       0.274119        17.4363       0.274119        17.2417

### 3

TimeSteps = 50
Samples = 1000000

                              old engine                  non constant                      constant      
           kind            NPV       time [s]            NPV       time [s]            NPV       time [s] 
       European        4.16453        11.7625        4.16453        11.6316        4.16453        11.6616 
          Asian       0.729431        2.29277       0.729431        2.28119       0.729431        2.29708 
        Barrier       0.274529        16.2723       0.274529        16.1431       0.274529        16.0514 


We can see that our modifications did not corrupt it as we get the same results as before, however it did not improve performance.