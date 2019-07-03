# Check for OpenCV
find_package( OpenCV QUIET )

if ( ${libZaber_FOUND} AND ${libWaferProb_FOUND} )
  include_directories( ../libZaber/include )
  include_directories( ../libWaferProb/include )
  include_directories( ../libGPIB/include) 

  # add one exectable foreach 
  add_executable(eg_zaber eg_zaber.cpp)
  target_link_libraries(eg_zaber Zaber)

  add_executable(agilent_test agilentRigolLike_example.cpp)
  target_link_libraries(agilent_test GPIB)

  add_executable(motion_controller motion_controller.cpp)
  target_link_libraries(motion_controller Zaber WaferProb)

  add_executable(lowering_test lowering_test.cpp)
  target_link_libraries(lowering_test Zaber WaferProb GPIB)
   

  include_directories( ../libImageRec/include )
  add_executable(test_opencv_camera test_opencv_camera.cpp)
  target_link_libraries(test_opencv_camera ${OpenCV_LIBS})

  #add_executable(test_sift test_sift.cpp)
  #target_link_libraries(test_sift ImageRec ${OpenCV_LIBS})
else()
  message("Disabling prober due to missing dependencies")
  message(" libZaber = ${libZaber_FOUND}")
  message(" libWaferProb = ${libWaferProb_FOUND}")
endif()
