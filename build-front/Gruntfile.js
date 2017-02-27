module.exports = function(grunt) {

    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),
    
        less: {
            development: {
                options: {
                    paths: ['less'],
                    compress: false,
                    cleancss: true,
                    dumpLineNumbers: 'comments'
                },
                files: {
                    '../themes/bookbox_ui/css/style.css': '../themes/bookbox_ui/less/style.less'
                }
            }
        },

        bake: {
            your_target: {
                options: {
                    // Task-specific options go here.
                },

                files: {
                    // files go here, like so:
                    "../themes/bookbox_ui/templates/page.tpl.php": "../themes/bookbox_ui/_templates-src/page.tpl.php",
                    "../themes/bookbox_ui/templates/page--type-book.tpl.php": "../themes/bookbox_ui/_templates-src/page--type-book.tpl.php"
                }
            }
        },

        watch: {
            grunt: {
                files: ['Gruntfile.js']
            },

            less: {
                files: [
                    '../themes/bookbox_ui/less/**/*.less',
                    '../themes/bookbox_ui/less/**/**/*.less'
                ],
                tasks: ['less', 'postcss']
            },

            bake: {
                files: [
                    '../themes/bookbox_ui/_templates-src/**/*.php'
                ],
                tasks: ['bake']
            }

        },
        
        postcss: {
            options: {
              processors: [
                require('autoprefixer')({browsers: ['last 2 versions', 'ie 10']})
              ]
            },
            dist: {
              src: '../themes/bookbox_ui/css/style.css'
            }
        }
    });

    // load npm modules
    grunt.loadNpmTasks('grunt-bake');
    grunt.loadNpmTasks('grunt-contrib-less');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-postcss');

    // register tasks
    grunt.registerTask('default', ['less', 'bake', 'postcss', 'watch']);
    grunt.registerTask('jenkins', ['less', 'bake', 'postcss']);
   
    //grunt.registerTask('default', ['less', 'postcss', 'copy:main', 'watch']);
   // grunt.registerTask('jenkins', ['less', 'postcss', 'copy:main']);
};
