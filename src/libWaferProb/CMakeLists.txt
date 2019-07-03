if ( ${libZaber_FOUND} )
  # Add the headers
  include_directories( include )
  include_directories( ../libZaber/include )
  include_directories( ../libGPIB/include )

  # Add all *.c* files as source code
  file(GLOB SrcFiles *.c*)
  add_library(WaferProb SHARED ${SrcFiles}) 
  target_link_libraries(WaferProb Zaber GPIB)

  # Tell rest of labRemote that the library exists
  set(libWaferProb_FOUND TRUE PARENT_SCOPE)
else()
  message("Disabling libWaferProb due to missing dependencies")
  message(" libZaber = ${libZaber_FOUND}")

  set(libWaferProb_FOUND FALSE PARENT_SCOPE)
endif()
